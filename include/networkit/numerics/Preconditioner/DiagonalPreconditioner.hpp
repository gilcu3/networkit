/*
 * DiagonalPreconditioner.h
 *
 *  Created on: Apr 23, 2016
 *      Author: Michael Wegner (michael.wegner@student.kit.edu)
 */

#ifndef NETWORKIT_CPP_NUMERICS_PRECONDITIONER_DIAGONALPRECONDITIONER_H_
#define NETWORKIT_CPP_NUMERICS_PRECONDITIONER_DIAGONALPRECONDITIONER_H_

#include <networkit/algebraic/CSRMatrix.hpp>

namespace NetworKit {

/**
 * @ingroup numerics
 * Simple preconditioner that approximates the matrix by a
 * diagonal matrix.
 */
class DiagonalPreconditioner {
public:
    /** Default constructor */
    DiagonalPreconditioner() = default;

    /**
     * Constructs a diagonal preconditioner for the matrix @a A.
     * @param A
     */
    DiagonalPreconditioner(const CSRMatrix& A) : inv_diag(A.numberOfRows()) {
        assert(A.numberOfColumns() == A.numberOfRows());

        // Diagonal preconditioner just needs to store the inverse diagonal of A
        inv_diag = A.diagonal();
#pragma omp parallel for
        for (omp_index i = 0; i < static_cast<omp_index>(inv_diag.getDimension()); ++i) {
            if (inv_diag[i]) inv_diag[i] = 1.0 / inv_diag[i];
        }
    }

    virtual ~DiagonalPreconditioner() = default;

    /**
     * Returns the preconditioned right-hand-side \f$P(b) = D(A)^{-1}b\f$.
     */
    Vector rhs(const Vector& b) const {
        assert(b.getDimension() == inv_diag.getDimension());
        Vector out(b.getDimension());
        for (index i = 0; i < b.getDimension(); ++i) {
            out[i] = inv_diag[i] * b[i];
        }
        return out;
    }

private:
    Vector inv_diag;
};

} /* namespace NetworKit */

#endif /* NETWORKIT_CPP_NUMERICS_PRECONDITIONER_DIAGONALPRECONDITIONER_H_ */
