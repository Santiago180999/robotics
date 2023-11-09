#ifndef IGRAPHREADER2D
#define IGRAPHREADER2D

#include "IGraphReader.hpp"
#include <vector>
#include <tuple>

namespace CoreCpp
{
    // make this a visitor class... i know i just re created this; but its a good way to practice design patterns
    class GraphReader2d : public IGraphReader
    {

        public:
            /**
             * @brief constructor of the reader
             * @param rFilePath Filepath to read
             * @param csv true if file is csv, false if file is json
            */
            GraphReader2d(std::string rFilePath, bool isCsv);

            /**
             * @brief Json reader implementation for a 2d graph with edge cost
             * @note if this becomes a visitor class, JsonReader would have the Graph2d passed as a parameter
            */
            CoreCpp::StatusCode JsonReader() override;

            /**
             * @brief Csv reader implementation for a 2d graph with edge cost
            */
            CoreCpp::StatusCode CsvReader() override;


            std::vector<std::tuple<int, int, int>> m_nodes; // (id, x, y)
            std::vector<std::tuple<int, int, float>> m_edges; // (src, dest, cost)
        private:
            std::string m_filePath;
            bool m_isCsv;

            

    };
}




#endif