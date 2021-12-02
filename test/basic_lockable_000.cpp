#include "valkyrie_engine/basic_lockable.hpp"
#include "valkyrie_engine/valkyrie_engine.hpp"

#include "catch2/catch.hpp"

class my_lockable : public vlk::basic_lockable {};

SCENARIO("basic_lockables can be locked")
{
	GIVEN("an instance of basic_lockable")
	{
		vlk::basic_lockable lockable;

		WHEN("the lockable is write-locked")
		{
			auto lock = lockable.lock_write();

			THEN("the lockable's mutex is unique locked")
			{
				REQUIRE(!lockable.mutex().try_lock());
				REQUIRE(!lockable.mutex().try_lock_shared());
			}
		}

		WHEN("the lockable is read-locked")
		{
			auto lock = lockable.lock_read();

			THEN("the lockable's mutex is shared locked")
			{
				REQUIRE(!lockable.mutex().try_lock());
				REQUIRE(lockable.mutex().try_lock_shared());
			}
		}
	}

	GIVEN("a write-locked basic_lockable")
	{
		vlk::basic_lockable lockable;
		auto lock = lockable.lock_write();

		WHEN("the lock is unlocked")
		{
			lock.unlock();

			THEN("the lockable's mutex can be unique locked again")
			{
				REQUIRE(lockable.mutex().try_lock());
			}

			THEN("the lockable's mutex can be shared locked again")
			{
				REQUIRE(lockable.mutex().try_lock_shared());
			}
		}
	}

	GIVEN("a read-locked basic_lockable")
	{
		vlk::basic_lockable lockable;
		auto lock = lockable.lock_read();

		WHEN("the lock is unlocked")
		{
			lock.unlock();

			THEN("the lockable's mutex can be unique locked again")
			{
				REQUIRE(lockable.mutex().try_lock());
			}

			THEN("the lockable's mutex can be shared locked again")
			{
				REQUIRE(lockable.mutex().try_lock_shared());
			}
		}
	}
}
