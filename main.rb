require 'prime'

class HashTable
  def initialize(initial_size)
    size = initial_size 
    loop {
      break if size.prime?
      size += 1
    }
    @size = size
    @table = []
  end

  def hash(str)
    str.split('').inject(0) { |p, c| p + c.ord }
  end

  def shift(key, slot)
    key + slot.to_s
  end

  def old_set(key, value)
    slot = hash(key) % @size
    @table[slot] = {
      :key => key,
      :value => value
    }
  end

  def set(initial_key, value)
    key = initial_key
    loop {
      slot = hash(key) % @size
      v = @table[slot]
      if v.nil? || v[:key] == initial_key
        @table[slot] = {
          :key => initial_key,
          :value => value
        }
        break
      else
        key = shift(initial_key, slot)
      end
    }
  end

  def old_get(key)
    slot = hash(key) % @size
    v = @table[slot]
    v ? v[:value] : ''
  end

  def get(initial_key)
    key = initial_key
    loop {
      slot = hash(key) % @size
      v = @table[slot]
      return nil if v.nil?
      if v[:key] == initial_key
        return v[:value]
      else
        key = shift(initial_key, slot)
      end
    }
    v ? v[:value] : ''
  end

  def fit(str, len)
    (str.to_s + ' ' * len)[0, len]
  end

  def show()
    @table.each_with_index { |v, i|
      index = i
      key = v ? v[:key] : ' '
      value = v ? v[:value] : ' '
      get_value = v ? get(key) : ' '
      diff = v ? (v[:value] != get(key) ? 'x' : 'o') : ' '
      puts "#{fit(index, 2)} | #{fit(key, 8)} | #{fit(value, 2)} | #{fit(get_value, 2)} | #{diff}"
    }
    puts "size: #{@table.length} filled: #{@table.compact.length}"
  end
end

data = ['Lorem', 'ipsum', 'dolor', 'sit', 'amet', 'consectetur', 'adipisicing', 'elit', 'Doloribus', 'obcaecati', 'nam', 'recusandae', 'maxime', 'quae', 'cumque', 'quod', 'dolores', 'laborum', 'a', 'officiis', 'ratione?', 'Iure', 'quaerat', 'similique', 'quidem', 'obcaecati', 'inventore', 'eius', 'omnis', 'reiciendis']

ht = HashTable.new(data.length)
data.each_with_index { |v, i|
  ht.set(v, i)
}
ht.show()
