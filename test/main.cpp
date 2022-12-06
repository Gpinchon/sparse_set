#include <sparse_set.hpp>

#include <cassert>

struct Transform {
    std::array<float, 3> position{ 0, 0, 0 };
};

int main()
{
    auto sparseSet = new sparse_set<Transform, 65536>;
    for (auto i = 0u; i < sparseSet->max_size(); ++i) {
        sparseSet->insert(i).position[0] = float(i);
    }
    for (auto i = 0u; i < sparseSet->size(); ++i) {
        assert(sparseSet->at(i).position[0] == i);
    }
    for (auto i = 0u; i < sparseSet->max_size(); ++i) {
        if (i % 3) sparseSet->erase(i);
    }
    for (auto i = 0u; i < sparseSet->max_size(); ++i) {
        if (i % 3) assert(!sparseSet->contains(i));
        else assert(sparseSet->contains(i));
    }
    delete sparseSet;
}