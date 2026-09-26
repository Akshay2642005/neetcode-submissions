struct LRUCache {
    cap: usize,
    map: HashMap<i32, usize>,
    order: Vec<i32>,
}

impl LRUCache {
    pub fn new(capacity: i32) -> Self {
        Self {
            cap: capacity as usize,
            map: HashMap::new(),
            order: Vec::new(),
        }
    }

    fn touch(&mut self, key: i32) {
        if let Some(pos) = self.order.iter().position(|&k| k == key) {
            self.order.remove(pos);
        }
        self.order.push(key);
    }
    pub fn get(&mut self, key: i32) -> i32 {
        if let Some(&val) = self.map.get(&key) {
            self.touch(key);
            return val as i32;
        }
        return -1
    }

    pub fn put(&mut self, key: i32, value: i32) {
        if self.map.contains_key(&key) {
            self.touch(key);
        } else {
            if self.map.len() == self.cap {
                let lru = self.order.remove(0);
                self.map.remove(&lru);
            }
            self.order.push(key);
        }
        self.map.insert(key, value as usize);
    }
}
