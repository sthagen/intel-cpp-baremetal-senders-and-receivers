#include <async/concepts.hpp>
#include <async/connect.hpp>
#include <async/just.hpp>

// EXPECT: Can't connect sender and receiver

struct fail_receiver {
    using is_receiver = void;
};
static_assert(async::receiver<fail_receiver>);

auto main() -> int {
    [[maybe_unused]] auto op =
        async::connect(async::just_error(42), fail_receiver{});
}
