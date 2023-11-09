#ifndef IGRAPHREADER2D
#define IGRAPHREADER2D

#include "IGraphReader.hpp"
#include <vector>
#include <tuple>

namespace CoreCpp
{

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
            */
            CoreCpp::StatusCode JsonReader() override;

            /**
             * @brief Csv reader implementation for a 2d graph with edge cost
            */
            CoreCpp::StatusCode CsvReader() override;
        
        private:
            std::string m_filePath;
            bool m_isCsv;

            std::vector<std::tuple<int, int, int>> m_nodes; // (id, x, y)
            std::vector<std::tuple<int, int, float>> m_edges; // (src, dest, cost)

    };
}




#endif