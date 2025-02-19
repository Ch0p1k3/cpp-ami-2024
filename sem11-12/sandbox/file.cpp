#include <fstream>
#include <ios>

namespace common::util::detail {


#define CONCAT(X, Y) CONCAT_IMPL_I(X, Y)
#define CONCAT_IMPL_I(X, Y) CONCAT_IMPL_II(X, Y)
#define CONCAT_IMPL_II(X, Y) X##Y

#define GENERATE_UNIQUE_ID(category) CONCAT(category, __COUNTER__)

template <class Func>
class DeferHelperRunner {
public:
    explicit DeferHelperRunner(Func func)
        : func_{func} {
    }

    ~DeferHelperRunner() {
        func_();
    }

private:
    Func func_;
};

struct DeferHelperExpander {
    template <class Func>
    DeferHelperRunner<Func> operator||(Func func) const {
        return DeferHelperRunner<Func>{func};
    }
};

} // namespace common::util::detail

#define defer const auto GENERATE_UNIQUE_ID(defer_) = common::util::detail::DeferHelperExpander{} || [&]

int main() {
    std::fstream f("file.txt", std::ios_base::out | std::ios_base::trunc);
    defer {
        f.close();
    };
    f << "Hello, world!" << std::endl;
}
