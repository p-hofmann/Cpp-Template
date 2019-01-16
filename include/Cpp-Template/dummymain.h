/**
 * Created by Peter Hofmann on 14.01.19.
 */

#ifndef CPP_TEMPLATE_DUMMYMAIN_H
#define CPP_TEMPLATE_DUMMYMAIN_H

#include <string>
#include "cpptemplatesub1.h"
#include "filesystem.h"

using namespace SubModule1;

namespace dummy
{
    class DummyMain : public CppTemplateSub1Sub
    {
    public:
        /**
         * Name of Class
         * Returns name of the class
         * @return Class name
         */
        DummyMain() : CppTemplateSub1Sub("DummyMain") {}

        std::string toString();
    };
}

#endif //CPP_TEMPLATE_DUMMYMAIN_H
