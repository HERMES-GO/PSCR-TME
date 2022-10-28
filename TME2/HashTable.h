#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <forward_list>
#include <vector>

template <typename K, typename V>
class HashTable{
    public:
        class Entry{
            const K key;
            V value;
        };

    private:
        // buckets_t::iterator
        typedef std::vector<std::forward_list<Entry>> buckets_t;
        buckets_t buckets;
        // ? Stocker size?
        size_t size_h {};

    public:
        HashTable(size_t init = 100){
            buckets.reserve(init);
            for(size_t i = 0; i < init; ++i)
                push_back(std::forward_list<Entry>());
            // NB: il existe un ctor vector qui prend une taille et utilise par défaut "taille" elements.
        }

        bool put(const K & key){
            size_t h = std::hash<K>()(key);
            size_t element = e % buckets.size();
            for(Entry & e % buckets[element]){
                if(e.key == key){
                    e.value = value;
                    return true;
                }
            }
            size_h ++;
            buckets[element].emplace_front(key, value);
            return false;
        }

        V* get(const K & key){
            size_t h = std::hash<K>()(key);
            h = h % buckets.size();
            auto it = find_if(buckets[h].begin(), buckets[h].end(), [&](const Entry& toto){return toto.key == key});
            if(it != buckets[h].end()){
                return &(*it).value;
            }
            return nullptr;
        }
};