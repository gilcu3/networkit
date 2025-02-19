/*
 * Coverage.h
 *
 *  Created on: 02.02.2013
 *      Author: Christian Staudt (christian.staudt@kit.edu)
 */

#ifndef COVERAGE_H_
#define COVERAGE_H_

#include <networkit/community/QualityMeasure.hpp>

namespace NetworKit {

/**
 * @ingroup community
 * Coverage is the fraction of intra-cluster edges.
 */
class Coverage: public QualityMeasure {
public:

    virtual double getQuality(const Partition& zeta, const Graph& G);
};

} /* namespace NetworKit */
#endif /* COVERAGE_H_ */
