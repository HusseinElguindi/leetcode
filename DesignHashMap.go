type node struct {
    key int
    val int
    next *node
}
type MyHashMap struct {
    buckets []*node
    maxSize int
}

// Print - display the hashmap
func (this *MyHashMap) Print() {
    for i, b := range this.buckets {
        fmt.Printf("Bucket %d: ", i)
        cur := &b
        for *cur != nil {
            fmt.Print(**cur, " -> ")
            cur = &(**cur).next
        }
        fmt.Println("nil")
    }
}

// Constructor - initialize a new hashmap
// the hashmap is initialized with a number of buckets equal to half the max size
func Constructor() MyHashMap {
    m := MyHashMap{
        maxSize: 10000,
    }
    m.buckets = make([]*node, m.maxSize / 2)
    return m
}

// hash - return the bucket index from a key
func (this *MyHashMap) hash(key int) int {
    return key % this.maxSize
}

// Put - insert or update a key with the passed value
func (this *MyHashMap) Put(key int, value int)  {
    // Calculate the hash index
    hashKey := this.hash(key)
    
    // Resize if needed
    reqLen := hashKey + 1
    if len(this.buckets) < reqLen {
        this.buckets = append(this.buckets, make([]*node, reqLen)...)
    }
    
    // Find the insertion position of this node
    // or update node if matched
    cur := &this.buckets[hashKey]
    for *cur != nil {
        if (**cur).key == key {
            // Update value
            (**cur).val = value
            return
        }
        cur = &(**cur).next
    }
    
    // Create and append the new node
    *cur = &node{
        key: key,
        val: value,
        next: nil,
    }
}


// Get - return the value for the passed key
// returns -1 for an unfound key
func (this *MyHashMap) Get(key int) int {
    cur, ok := this.getNode(key)
    if !ok {
        return -1
    }
    return (**cur).val
}


// Remove - deletes a key and its value from the hashmap
// returns if they key is not found
func (this *MyHashMap) Remove(key int)  {
    cur, ok := this.getNode(key)
    if !ok {
        return
    }
    *cur = (**cur).next
}

// getNode - returns a mutable reference to the position of a node, 
// and a bool specifying if the key was found
func (this *MyHashMap) getNode(key int) (**node, bool) {
    // Calculate the hash index
    hashKey := this.hash(key)
    
    // Not found if its bucket does not exist
    if len(this.buckets) < hashKey + 1 {
        return nil, false
    }
    
    // Traverse and match collisions, if any
    cur := &this.buckets[hashKey]
    for *cur != nil {
        if (**cur).key == key {
            return cur, true
        }
        cur = &(**cur).next
    }
    
    // Not found
    return nil, false
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */
