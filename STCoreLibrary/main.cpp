//
//  main.cpp
//  STCoreLibrary
//
//  Created by 이종일 on 2020/11/12.
//

#include <iostream>
#include "constants.hpp"
#include "input_parser.hpp"
#include "showtap_file_reader.hpp"

using namespace std;

int main(int argc, char **argv) {
    InputParser input(argc, argv);
    
    if(input.exist(ARGS_HELP)){
        cout << "--- Showtap Core Library Help --- \n -f (file) : File Path \n ";
        
        return 1;
    }
    
    if(input.exist(ARGS_READ)){
        if(!input.exist(ARGS_R_FILE_PATH)) return ERR_SOURCE_EMPTY;
        
        string src = input.getCommandOption(ARGS_R_FILE_PATH);
        
        FileReader reader(src);
        
        reader.setDestination("/data/data/showtap.stap");
        
        int ret = reader.extract();
        
        return ret;
    }
    
    if(input.exist(ARGS_SAVE)){
        cout << "SAVE FILE";
        
        return RESULT_OK;
    }
    
    return -1;
}
