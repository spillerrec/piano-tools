/*	This file is part of piano-tools, which is free software and is licensed
 * under the terms of the GNU GPL v3.0. (see http://www.gnu.org/licenses/ ) */
#ifndef NOTATION__DURATION_HPP
#define NOTATION__DURATION_HPP

namespace Notation{

struct Duration{
	uint16_t nominator;
	uint16_t denominator;
	
	Duration( uint16_t n, uint16_t d ) : nominator(n), denominator(d) { }
};
//TODO: basic math operations

}
#endif
