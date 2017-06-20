//
// Created by alice on 19/06/17.
//

#ifndef CLIENT_D_ZAPPY_HPP
#define CLIENT_D_ZAPPY_HPP

extern "C"
{
# include "mendatory/client.h"
# include "mendatory/connection_manager.h"
};

namespace zappy {
    class Zappy {
    public:
        Zappy(int, char **);
        ~Zappy();

        void run();
        void stop();
    private:
        t_arg           _arg;
        t_cookie        _cook;
        t_fd_manager    _fd_manager;
        t_thread_data   _relay_manager;
    };
}

#endif //CLIENT_D_ZAPPY_HPP
