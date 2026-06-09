#include "../given/bigInt.hpp"

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int num) {
    std::ostringstream oss;
    oss << num;
    this->str = oss.str();
}

bigint::bigint(const bigint& source) : str(source.str) {}

bigint& bigint::operator=(const bigint& source) {
    if (this != &source) {
        this->str = source.str;
    }
    return *this;
}

std::string bigint::getStr() const {
    return this->str;
}

std::ostream& operator<<(std::ostream& os, const bigint& obj) {
    os << obj.getStr();
    return os;
}

bigint& bigint::operator+=(const bigint& other) {
    // Grade-school addition from right to left.
    std::string res = "";
    int carry = 0;
    int i = this->str.length() - 1;
    int j = other.str.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += this->str[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += other.str[j] - '0';
            j--;
        }
        res += (sum % 10) + '0';
        carry = sum / 10;
    }

    std::string final_res = "";
    for (int k = res.length() - 1; k >= 0; --k) {
        final_res += res[k];
    }

    int non_zero = 0;
    while (non_zero < (int)final_res.length() && final_res[non_zero] == '0') {
        non_zero++;
    }

    if (non_zero == (int)final_res.length()) {
        this->str = "0";
    } else {
        this->str = final_res.substr(non_zero);
    }

    return *this;
}

bigint bigint::operator+(const bigint& other) const {
    bigint tmp(*this);
    tmp += other;
    return tmp;
}

bigint& bigint::operator++() {
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int) {
    bigint tmp(*this);
    ++(*this); // DRY
    return tmp;
}

bool bigint::operator==(const bigint& other) const {
    return this->str == other.str;
}

bool bigint::operator!=(const bigint& other) const {
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const {
    if (this->str.length() != other.str.length()) {
        return this->str.length() < other.str.length();
    }
    return this->str < other.str;
}

bool bigint::operator>(const bigint& other) const {
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}


bigint& bigint::operator<<=(unsigned int n) {
    if (this->str == "0") return *this;

    // Base-10 digit shift left: append n zeros.
    for (unsigned int i = 0; i < n; ++i) {
        this->str += '0';
    }
    return *this;
}

bigint bigint::operator<<(unsigned int n) const {
    bigint tmp(*this);
    tmp <<= n;
    return tmp;
}

bigint& bigint::operator>>=(unsigned int n) {
    // Base-10 digit shift right: remove n trailing digits.
    if (n >= this->str.length()) {
        this->str = "0";
    } else {
        this->str = this->str.substr(0, this->str.length() - n);
    }
    return *this;
}

bigint bigint::operator>>(unsigned int n) const {
    bigint tmp(*this);
    tmp >>= n;
    return tmp;
}


bigint& bigint::operator<<=(const bigint& other) {
    unsigned int n = std::strtoul(other.str.c_str(), NULL, 10);
    return (*this <<= n);
}

bigint bigint::operator<<(const bigint& other) const {
    bigint tmp(*this);
    tmp <<= other;
    return tmp;
}

bigint& bigint::operator>>=(const bigint& other) {
    unsigned int n = std::strtoul(other.str.c_str(), NULL, 10);
    return (*this >>= n);
}

bigint bigint::operator>>(const bigint& other) const {
    bigint tmp(*this);
    tmp >>= other;
    return tmp;
}
