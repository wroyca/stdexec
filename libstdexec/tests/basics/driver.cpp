#include <stdexec/execution.hpp>
#include <exec/static_thread_pool.hpp>

#undef NDEBUG
#include <cassert>

#include <utility>

int main ()
{
  exec::static_thread_pool pool (2);

  auto work = stdexec::starts_on (
    pool.get_scheduler (),
    stdexec::just (40) | stdexec::then ([] (int i) {return i + 2;}));

  auto [i] = stdexec::sync_wait (std::move (work)).value ();
  assert (i == 42);
}
