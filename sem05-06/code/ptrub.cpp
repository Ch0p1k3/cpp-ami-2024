struct Foo {
    int a;
};

int GetA(const Foo* f) {
    int a = f->a;
    if (f == nullptr) {
        return -1;
    }
    return a;
}
