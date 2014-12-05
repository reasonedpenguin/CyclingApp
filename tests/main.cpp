
#include "tst_importtest.h"
#include "tst_exporttest.h"

int main(int argc, char** argv)
{
   int status = 0;
   {
       ImportTest tc;
      status |= QTest::qExec(&tc, argc, argv);
   }
   {
       ExportTest tc;
      status |= QTest::qExec(&tc, argc, argv);
   }
   return status;
}
