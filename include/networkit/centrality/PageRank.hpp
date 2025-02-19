/*
 * PageRank.h
 *
 *  Created on: 19.03.2014
 *      Author: Henning
 */

#ifndef PAGERANK_H_
#define PAGERANK_H_

#include <networkit/centrality/Centrality.hpp>

namespace NetworKit {

/**
 * @ingroup centrality
 * Compute PageRank as node centrality measure.
 * NOTE: There is an inconsistency in the definition in Newman's book (Ch. 7) regarding
 * directed graphs; we follow the verbal description, which requires to sum over the incoming
 * edges (as opposed to outgoing ones).
 */
class PageRank: public Centrality {
protected:
    double damp;
    double tol;

public:
    /**
     * Constructs the PageRank class for the Graph @a G
     *
     * @param[in] G Graph to be processed.
     * @param[in] damp Damping factor of the PageRank algorithm.
     * @param[in] tol Error tolerance for PageRank iteration.
     */
    PageRank(const Graph& G, double damp=0.85, double tol = 1e-8);

    /**
     * Computes page rank on the graph passed in constructor.
     */
    virtual void run();

    /**
     * Returns upper bound on the page rank: 1.0. This could be tighter by assuming e.g. a star graph with n nodes.
     */
    virtual double maximum();
};

} /* namespace NetworKit */
#endif /* PAGERANK_H_ */
