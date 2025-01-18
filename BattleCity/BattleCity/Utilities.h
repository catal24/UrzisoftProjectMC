template <typename T>
bool IsInBounds(T value, T min, T max) {
    return (value >= min && value <= max);
}
