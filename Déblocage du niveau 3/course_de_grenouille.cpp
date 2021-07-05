#include <iostream>
#include <map>
#include <iterator>

class data {
  public:
    size_t times_first, distance;
    data() : times_first{0}, distance{0}{};
};

// void printMap(std::map<size_t, data> n) {
//     std::map<size_t, data>::iterator itr;
//     for (itr = n.begin(); itr != n.end(); itr++) {
//         std::cout << itr->first << " : " << itr->second.distance << " , " << itr->second.times_first << std::endl;
//     }
// }

int main(int argc, char const *argv[]){
    size_t nbGrenouilles, nbTours;
    
    std::cin >> nbGrenouilles;
    std::cin >> nbTours;

    // std::cout << nbGrenouilles << nbTours << std::endl;

    std::map<size_t, data> score{};
    for (size_t i = 0; i < nbGrenouilles; i++) {
        score.insert(std::pair<size_t, data>(i, data()));
    }

    for (size_t i = 0; i < nbTours; i++){
        // find which frog has highest distance and increment its time first
        size_t maxIdx{0};
        bool isSingle{1};
            // iterate over every item in map
        std::map<size_t, data>::iterator itr;
        for (itr = score.begin(); itr != score.end(); itr++) {
            // Skip when i is 0
            if (itr->first == 0)
                continue;
            if (score[itr->first].distance > score[maxIdx].distance) {
                maxIdx = itr->first;
                isSingle = true;
            } else if (score[itr->first].distance == score[maxIdx].distance) {
                isSingle = false;
            }
        }
        
        if (isSingle) {
            score[maxIdx].times_first++;
        }

        // input next round info
        size_t index, distance;
        std::cin >> index >> distance;
        // std::cout << "H:" << index << " " << distance << std::endl;
        // add distance to frog's data()
        score[index-1].distance += distance;
    }

    // find which frog(s) have highest times first
    std::map<size_t, data>::iterator itr;
    size_t maxIdx{0};
    for (itr = score.begin(); itr != score.end(); itr++) {
        if (itr->first == 0)
            continue;
        if (score[itr->first].times_first > score[maxIdx].times_first) {
            maxIdx = itr->first;
        }
    }
    // printMap(score);
    std::cout << maxIdx + 1 << std::endl;
    return 0;
}
