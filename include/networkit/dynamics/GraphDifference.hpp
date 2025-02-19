#ifndef GRAPHDIFFERENCE_H
#define GRAPHDIFFERENCE_H

#include <networkit/graph/Graph.hpp>
#include <networkit/dynamics/GraphEvent.hpp>
#include <networkit/base/Algorithm.hpp>

namespace NetworKit {

/**
 * Calculate the edge difference between two graphs.
 *
 * This calculates which graph edge additions or edge removals are
 * necessary to transform one given graph into another given graph.
 *
 * Both graphs need to have the same node set, directed graphs are not
 * supported currently.
 *
 * Note that edge weight differences are not detected but edge
 * addition events set the correct edge weight.
 */
class GraphDifference : public Algorithm {
public:
    /**
     * Construct the edge edit difference with two graphs to compare.
     *
     * @param G1 The first graph to compare.
     * @param G2 The second graph to compare.
     */
    GraphDifference(const Graph &G1, const Graph &G2);

    /**
     * Execute the algorithm and compute the difference.
     */
    virtual void run() override;

    /**
     * Get the required edits.
     *
     * @return A vector of graph events.
     */
    std::vector<GraphEvent> getEdits() const;

    /**
     * Get the required number of edits.
     *
     * This is only the number of actual changes.
     * In order to get correct node ids, more edits might be generated.
     *
     * @return The number of edits.
     */
    count getNumberOfEdits() const;

    /**
     * Get the required number of node addtions.
     *
     * @return The number of node additions.
     */
    count getNumberOfNodeAdditions() const;

    /**
     * Get the required number of node removals.
     *
     * @return The number of node removals.
     */
    count getNumberOfNodeRemovals() const;

    /**
     * Get the required number of node restorations.
     *
     * @return The number of node restorations.
     */
    count getNumberOfNodeRestorations() const;

    /**
     * Get the required number of edge addtions.
     *
     * @return The number of edge additions.
     */
    count getNumberOfEdgeAdditions() const;

    /**
     * Get the required number of edge removals.
     *
     * @return The number of edge removals.
     */
    count getNumberOfEdgeRemovals() const;

    /**
     * Get the required number of edge weight updates.
     *
     * @return The number of edge weight updates.
     */
    count getNumberOfEdgeWeightUpdates() const;
private:
    const Graph &G1, &G2;
    std::vector<GraphEvent> edits;
    count numEdits;
    count numNodeAdditions;
    count numNodeRemovals;
    count numNodeRestorations;
    count numEdgeAdditions;
    count numEdgeRemovals;
    count numWeightUpdates;
};

} // namespace NetworKit

#endif // GRAPHDIFFERENCE_H
