#pragma once

#include <string_view>
#include <vector>

namespace vlk
{
	template <typename Event>
	class basic_event_listener
	{
		public:
		// Event listeners are referenced by the event bus according
		// to their pointers, so moving and copying are disallowed
		basic_event_listener(const basic_event_listener&) = delete;
		basic_event_listener(basic_event_listener&&) = delete;
		basic_event_listener& operator=(const basic_event_listener&) = delete;
		basic_event_listener& operator=(basic_event_listener&&) = delete;
		virtual ~basic_event_listener() = default;

		virtual inline bool requires_main_thread() { return false; }
		virtual inline std::string_view stage() const = 0;
		virtual inline std::vector<std::string_view> prerequisites() { return {}; }

		virtual void on_event(const Event& ev) = 0;
	};
}
