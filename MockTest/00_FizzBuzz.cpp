/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void fizzBuzz(int n) {
    for(int i = 1; i <= n; ++i){
        auto fg = false;
        if(!(i  % 3)){
            fg = true;
            std::cout << "Fizz";
        }
        if(!(i  % 5)){
            fg = true;
            std::cout << "Buzz";
        }
        if(!fg){
            std::cout << i;
        }
        std::cout << std::endl;
    }
}
