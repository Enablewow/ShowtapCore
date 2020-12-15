//
//  input_parser.hpp
//  STCoreLibrary
//
//  Created by 이종일 on 2020/11/12.
//

#ifndef input_parser_hpp
#define input_parser_hpp

#include <iostream>
#include <string>
#include <vector>

#endif /* input_parser_hpp */

class InputParser {
    private:
        std::vector <std::string> tokens;
        
    public:
        InputParser(int &argc, char** argv);
        
        const std::string& getCommandOption(const std::string &option) const;
        bool exist(const std::string &option) const;
};
