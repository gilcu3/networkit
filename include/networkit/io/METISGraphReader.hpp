/*
 * METISGraphReader.h
 *
 *  Created on: 17.01.2013
 *      Author: Christian Staudt (christian.staudt@kit.edu)
 */

#ifndef METISGRAPHREADER_H_
#define METISGRAPHREADER_H_

#include <networkit/io/GraphReader.hpp>

namespace NetworKit {

/**
 * @ingroup io
 * Reader for the METIS file format documented in [1]
 *
 * [1] http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/manual.pdf
 */
class METISGraphReader: public GraphReader {
public:

    METISGraphReader() = default;
    
    /**
     * Takes a file path as parameter and returns a graph file.
     *
     * @param[in]	path	file path
     *
     * @param[out]	the graph read from file
     */
    virtual Graph read(const std::string& path) override;
};

} /* namespace NetworKit */
#endif /* METISGRAPHREADER_H_ */
