

#ifndef DOCUMENT_READER_HPP
#define DOCUMENT_READER_HPP

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace CoreCpp
{
    /**
     * @brief Json Document reader. Should be made interface to be able to use csv
    */
    class DocumentReader
    {
        public:
        DocumentReader(std::string configFilePath);

        std::string m_configFilePath;
        json m_doc;

    };
}

#endif