/**
 * Created by Peter Hofmann on 14.01.19.
 */

#include "filesystem.h"
#include "Cpp-Template/dummymain.h"

using namespace dummy;

std::string DummyMain::toString()
{
    return CppTemplateSub1Sub::toString() + ", CWD: '" + filesystem::current_path() +"'";
}
