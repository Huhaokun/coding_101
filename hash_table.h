//
// Created by 胡昊坤 on 17/5/29.
//

#ifndef CODING_101_HASH_TABLE_H
#define CODING_101_HASH_TABLE_H

#include <string>
#include <vector>

/*
 * a thread-safe string key hash table
 * */
template <class V>
class StringKeyHashTable
{
public:
    StringKeyHashTable(size_t capacity);

    virtual ~StringKeyHashTable();

    void Put(const std::string& key, const V& val);

    bool Get(const std::string& key, V& val);

    void Remove(const std::string& key);

    bool ContainKey(const std::string& key);

    void Clear();

private:
    std::vector<V> elements_;
    std::vector<bool> existTable_;

    std::hash<std::string> hashFn_;
    size_t KeyToIndex(const std::string& key);

};

template <class V>
StringKeyHashTable<V>::StringKeyHashTable(size_t capacity) {
    elements_.resize(capacity);
    existTable_.resize(capacity);
}

template <class V>
StringKeyHashTable<V>::~StringKeyHashTable() {}

template <class V>
bool StringKeyHashTable<V>::Get(const std::string &key, V& val) {
    size_t idx = KeyToIndex(key);

    if (existTable_[idx])
    {
        val = elements_[idx];
        return true;
    } else {
        return false;
    }
}

template <class V>
void StringKeyHashTable<V>::Put(const std::string &key, const V &val) {
    size_t idx = KeyToIndex(key);

    //TODO handle the key conflict
    elements_[idx] = val;
    existTable_[idx] = true;
}

template <class V>
bool StringKeyHashTable<V>::ContainKey(const std::string &key) {
    size_t idx = KeyToIndex(key);
    return existTable_[idx];
}

template <class V>
size_t StringKeyHashTable<V>::KeyToIndex(const std::string &key) {
    return hashFn_(key) % elements_.size();
}

template <class V>
void StringKeyHashTable<V>::Clear() {
    elements_.clear();
}

template <class V>
void StringKeyHashTable<V>::Remove(const std::string &key) {
    size_t idx = KeyToIndex(key);
    existTable_[idx] = false;
}

#endif //CODING_101_HASH_TABLE_H
