import std;
import types;
import myu.cmdline;
int main( int argc, char *argv[]){
  if( quick_parse_args(argc, argv) == 1 ){
    return 0;
  }
  print("hi...\n");
  return 0;
}
