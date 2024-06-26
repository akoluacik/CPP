#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
int main(int argc, char *argv[]) {
    
    int arr[] = {1, 2, 3, 4, 4, 2, 1};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::vector<int> palVec(arr, arr + len);

    std::cout << "They are"; // print the common word in advance
    
    /* BY USING ITERATORS */
    
    /*std::vector<int>::iterator iter;                // for forward iteration
    std::vector<int>::reverse_iterator rev_iter;    // for reverse iteration*/
    

    /*for (iter = palVec.begin(), rev_iter = palVec.rbegin();  iter != palVec.end();  iter++, rev_iter++) { // advance the iterators while they are equal
            
        if( *iter != *rev_iter ) {
            std::cout << " not";
            break;
        }
    }*/
    
    /* BY USING at METHOD for PERFORMANCE CONSIDERATION */
    /* UNCOMMENT THE FOR LOOP BELOW TO GET CORRECT OUTPUT BY USING THE STATEMENT ABOVE */
    for (size_t i = 0; i < len / 2; i++)
        if(palVec.at(i) != palVec.at((len - 1) - i)) std::cout << " not";
    
    
    std::cout << " palindrome\n";

    /*for (rev_iter = palVec.rbegin(); rev_iter != palVec.rend() - (SIZE / 2) + 1; rev_iter++)
        std::cout << *rev_iter << ' ';*/

    

    return 0;
}