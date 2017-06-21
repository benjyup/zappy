//
// Created by alice on 20/06/17.
//

#ifndef CLIENT_D_PARSER_HPP
#define CLIENT_D_PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

namespace zappy {
    class parser {
    public:
        parser();
        ~parser();

        int lexer();
        std::string input;
    private:
      std::map<std::string, std::function<int(int)>> _function_ptr;
      int 		help_function(int);
      int     		flush_function(int);
    };
}

#endif //CLIENT_D_PARSER_HPP
