/*
 * DynamicPubWebGenerator.h
 *
 *  Created on: 15.01.2014
 *      Author: Henning
 */

#ifndef DYNAMICPUBWEBGENERATOR_H_
#define DYNAMICPUBWEBGENERATOR_H_

#include <map>

#include <networkit/generators/DynamicGraphGenerator.hpp>
#include <networkit/generators/PubWebGenerator.hpp>
#include <networkit/dynamics/GraphEvent.hpp>
#include <networkit/dynamics/DGSWriter.hpp>
#include <networkit/auxiliary/Random.hpp>
#include <networkit/viz/Point.hpp>

namespace NetworKit {

/**
 * @ingroup generators
 */
class DynamicPubWebGenerator: public DynamicGraphGenerator {

protected:
    PubWebGenerator initGen; // multiple inheritance did not work with different generate functions
    std::map<node, Point<float> > coordinates; //<! new and changed coordinates
    bool writeInitialGraphToStream; // if true, on first call, write initial graph to stream


public:
    DynamicPubWebGenerator(count numNodes, count numberOfDenseAreas,
            float neighborhoodRadius, count maxNumberOfNeighbors,
            bool writeInitialGraphToStream = true);


    Graph getGraph() const { return G; }

    /**
     * Generate event stream.
     *
     * @param[in]	nSteps	number of time steps in the event stream
     */
    virtual std::vector<GraphEvent> generate(count nSteps);


    virtual std::map<node, Point<float> > getNewCoordinates() const;



};

} /* namespace NetworKit */
#endif /* DYNAMICPUBWEBGENERATOR_H_ */
