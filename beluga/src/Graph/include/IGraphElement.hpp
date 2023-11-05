/**
 * @brief interface class of utils for graph elements
*/

#ifndef IGRAPH_ELEMENT_HPP
#define IGRAPH_ELEMENT_HPP

#include "CoreCppTypes.hpp"
#include "olcPixelGameEngine.h"

namespace GraphNs
{
    class IGraphElement
    {
        public:
            virtual ~IGraphElement() {};

            /**
             * @brief Convert the concrete class to print to terminal
            */
            virtual std::string ToString() = 0;

            /**
             * @brief Draw the concrete class using the olcPixelGameEngine
            */
            virtual CoreCpp::StatusCode Draw(olc::PixelGameEngine& rEngine) = 0;
    };
}

#endif