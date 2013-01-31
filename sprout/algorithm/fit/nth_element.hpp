#ifndef SPROUT_ALGORITHM_FIT_NTH_ELEMENT_HPP
#define SPROUT_ALGORITHM_FIT_NTH_ELEMENT_HPP

#include <sprout/config.hpp>
#include <sprout/iterator/distance.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fixed/nth_element.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/sub_array.hpp>

namespace sprout {
	namespace fit {
		namespace detail {
			template<typename Container, typename Compare>
			inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Container>::type
			nth_element_impl(
				Container const& cont, typename sprout::container_traits<Container>::const_iterator nth, Compare comp,
				typename sprout::container_traits<Container>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_internal(sprout::fixed::nth_element(cont, nth, comp)),
					offset,
					offset + sprout::distance(sprout::begin(cont), nth) + 1
					);
			}
		}	// namespace detail
		//
		// nth_element
		//
		template<typename Container, typename Compare>
		inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Container>::type
		nth_element(Container const& cont, typename sprout::container_traits<Container>::const_iterator nth, Compare comp) {
			return sprout::fit::detail::nth_element_impl(cont, nth, comp, sprout::internal_begin_offset(cont));
		}

		namespace detail {
			template<typename Container>
			inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Container>::type
			nth_element_impl(
				Container const& cont, typename sprout::container_traits<Container>::const_iterator nth,
				typename sprout::container_traits<Container>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_internal(sprout::fixed::nth_element(cont, nth)),
					offset,
					offset + sprout::distance(sprout::begin(cont), nth) + 1
					);
			}
		}	// namespace detail
		//
		// nth_element
		//
		template<typename Container>
		inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Container>::type
		nth_element(Container const& cont, typename sprout::container_traits<Container>::const_iterator nth) {
			return sprout::fit::detail::nth_element_impl(cont, nth, sprout::internal_begin_offset(cont));
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_ALGORITHM_FIT_NTH_ELEMENT_HPP
