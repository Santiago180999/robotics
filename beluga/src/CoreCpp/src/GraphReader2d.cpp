#include "GraphReader2d.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include "CoreCppTypes.hpp"
#include "spdlog/spdlog.h"

using json = nlohmann::json;

namespace CoreCpp
{
    GraphReader2d::GraphReader2d(std::string rFilePath, bool isCsv) : 
        m_filePath{rFilePath}, 
        m_isCsv{isCsv}
    {
        CoreCpp::StatusCode status;
        if(m_isCsv)
        {
            status = CsvReader();
        } 
        else
        {
            status = JsonReader();
        }
    }

    CoreCpp::StatusCode GraphReader2d::JsonReader()
    {
        std::ifstream f(m_filePath);
        if (!f.is_open())
        {
            spdlog::error("File couldnt be opened");
            return CoreCpp::Failure;
        }

        json doc = json::parse(f);
        json Nodes = doc.at("Nodes");
        json Edges = doc.at("Edges");
        int numNodes = doc.at("NumNodes");

        m_nodes.push_back(std::make_tuple(int(Nodes.at("id")), int(Nodes.at("x")), int(Nodes.at("y"))));
        m_edges.push_back(std::make_tuple(int(Edges.at("src")), int(Edges.at("dest")), float(Edges.at("cost"))));

        if (numNodes != m_nodes.size())
        {
            spdlog::error("Number of Nodes in file does not match number of nodes read in");
            return CoreCpp::Failure;
        }
        else
        {
            return CoreCpp::SUCCESS;
        }
    }

    CoreCpp::StatusCode GraphReader2d::CsvReader()
    {
        std::ifstream f(m_filePath);
        if (!f.is_open())
        {
            spdlog::error("File couldnt be opened");
            return CoreCpp::Failure;
        }

        std::string line;
        // read first line: NumNodes
        int numNodes;
        std::getline(f, line);
        std::stringstream ss(line);

        bool flag = false;
        for(std::string item; std::getline(ss, item, ',');)
        {
            if (flag)
            {
                // if the first item was numNodes, the number follows
                numNodes = std::stoi(item);
            }

            if (item == std::string("NumNodes"))
            {
                // check if first item was numNodes
                flag = true;
            } 
        }

        // skip 3 lines ahead
        for (int i=0; i<3; i++)
        {
            std::getline(f, line);
            // if (i == 1){spdlog::info(line);}
        }

        // node info begins
        int j;
        std::tuple<int, int, int> node; 
        for (int i=0; i<numNodes; i++)
        {
            std::getline(f, line);
            std::stringstream ss(line);
            j = 0;
            for(std::string item; std::getline(ss, item, ',');)
            {
                // spdlog::info(item);
                if (j == 0)
                {
                    std::get<0>(node) = std::stoi(item);
                    j++;
                }
                else if (j == 1)
                {
                    std::get<1>(node) = std::stoi(item);
                    j++;
                }
                else if (j == 2)
                {
                    std::get<2>(node) = std::stoi(item);
                    j++;
                }
            }
            m_nodes.push_back(node);
        }

        // check that number of nodes matches the expected
        if (numNodes != m_nodes.size())
        {
            spdlog::error("Number of Nodes in file does not match number of nodes read in");
            return CoreCpp::Failure;
        }
        // skip 3 lines ahead
        for (int i=0; i<3; i++)
        {
            std::getline(f, line);
            // if (i == 1){spdlog::info(line);}
        }

        // edge info begins
        std::tuple<int, int, float> edge; 
        while(std::getline(f, line))
        {
            std::stringstream ss(line);
            j = 0;
            for(std::string item; std::getline(ss, item, ',');)
            {
                // spdlog::info(item);
                if (j == 0)
                {
                    std::get<0>(edge) = std::stoi(item);
                    j++;
                }
                else if (j == 1)
                {
                    std::get<1>(edge) = std::stoi(item);
                    j++;
                }
                else if (j == 2)
                {
                    std::get<2>(edge) = std::stof(item);
                    j++;
                }
            }
            m_edges.push_back(edge);
        }
        f.close();
        return CoreCpp::SUCCESS;
    }
} // namespace CoreCpp