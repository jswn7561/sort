#include "BaseSort.h"
#include "BigValueSort.h"
#include "DistributedSort.h"

int main()
{
    BaseSort::Run();
    //BigValueSort::Run();
    DistributedSort::Run();
}
