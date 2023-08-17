

#include "DocumentReader.hpp"
#include "CoreCppTypes.hpp"
#include <fstream>

namespace CoreCpp
{
    DocumentReader::DocumentReader(std::string configFilePath) : m_configFilePath{configFilePath}
    {
        std::ifstream f(m_configFilePath);
        m_doc = json::parse(f);
    }
}