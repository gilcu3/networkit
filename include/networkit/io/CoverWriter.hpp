#ifndef COVERWRITER_H
#define COVERWRITER_H

#include <networkit/structures/Cover.hpp>
#include <networkit/graph/Graph.hpp>

namespace NetworKit {

/**
 * @ingroup io
 * Write a clustering to a file.
 */

class CoverWriter
{
    public:

        virtual void write(Cover& zeta, const std::string& path) const;
};
}

#endif // COVERWRITER_H
