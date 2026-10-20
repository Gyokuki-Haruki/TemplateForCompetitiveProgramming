#include <iostream>
#include <vector>

class BIT{
    public:
    BIT() = default;

    explicit BIT(size_t size)
        :m_bit(size + 1) {}

    explicit BIT(const std::vector<long long>& v)
    :BIT(v.size())
    {
        for(int i = 0; i < static_cast<int>(v.size()); i++){
            add((i + 1), v[i]);
        }
    }

    long long sum(int r) const {
        long long ret = 0;
        for(; 0 < r; r -= (r & -r)){
            ret += m_bit[r];
        }
        return ret;
    }

    //閉区間[l, r]の合計を返す(1-based indexing)
    long long sum(int l, int r) const{
        return (sum(r) - sum(l - 1));
    }

    void add(int i, long long value) {
        for(; i < static_cast<int>(m_bit.size()); i += (i & -i)) m_bit[i] += value;
    }

    private:
    std::vector<long long> m_bit;
};

//Binary Indexed Tree(区間加算対応)
// 1- based indexing
class BIT_RAQ {
    public:
    BIT_RAQ() = default;

    explicit BIT_RAQ(size_t size)
    : m_bit0(size)
    , m_bit1(size) {}

    explicit BIT_RAQ(const std::vector<long long>& v)
    : m_bit0(v)
    , m_bit1(v.size()) {}

    //閉区間[1, r]の合計を返す (1-based indexing)
    long long sum(int r) const {
        return (m_bit0.sum(r) + m_bit1.sum(r) * r);
    }


    //閉区間[l, r]の合計を返す (1-based indexing)
    long long sum(int l, int r) const {
        return (sum(r) - sum(l - 1));
    }

    //数列の i 晩円の要素を加算 (1-based indexing)
    void add(int i, long long value) {
        m_bit0.add(i, value);
    }

    //閉区間[l, r]の要素を加算 (1-based indexing)
    void add(int l, int r, long long value) {
        m_bit0.add(l, (-value * (l - 1)));
        m_bit0.add((r + 1), (value * r));
        m_bit1.add(l, value);
        m_bit1.add((r + 1), -value);
    }

    private:
    BIT m_bit0;
    BIT m_bit1;
};

int main(){
    int n; std::cin >> n;
    BIT bit(n);
}