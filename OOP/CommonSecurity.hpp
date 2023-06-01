#ifndef ALGORITHM_OALDRESPUZZLECRYPTIC_COMMONSECURITY_HPP
#define ALGORITHM_OALDRESPUZZLECRYPTIC_COMMONSECURITY_HPP

#include "SupportBaseFunctions.hpp"
#include "SecureSeedGenerator.hpp"

//通用安全工具
//Common Security Tools
namespace TwilightDreamOfMagical::CustomSecurity
{
	//ENUM: Cryption Mode To Multiple Cryptography Algorithm Core For File Data Worker
	enum class CryptionMode2MCAC4_FDW
	{
		MCA_ENCRYPTER,
		MCA_DECRYPTER,
		MCA_ENCODER,
		MCA_DECODER,
		MCA_PERMUTATION,
		MCA_PERMUTATION_REVERSE
	};

	template<std::integral DataType>
	struct UniformRandomBitGenerator
	{
		using result_type = DataType;

		static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
		static constexpr result_type min() { return std::numeric_limits<result_type>::min(); }
	};

	template<typename ByteType>
	requires std::is_same_v<ByteType, std::uint8_t> || std::is_same_v<ByteType, std::byte>
	class GaloisFiniteField256
	{

	private:
		static constexpr std::array<unsigned char, 256> LogarithmicTable
		{
			0x00, 0x00, 0x01, 0x19, 0x02, 0x32, 0x1a, 0xc6,
			0x03, 0xdf, 0x33, 0xee, 0x1b, 0x68, 0xc7, 0x4b,
			0x04, 0x64, 0xe0, 0x0e, 0x34, 0x8d, 0xef, 0x81,
			0x1c, 0xc1, 0x69, 0xf8, 0xc8, 0x08, 0x4c, 0x71,
			0x05, 0x8a, 0x65, 0x2f, 0xe1, 0x24, 0x0f, 0x21,
			0x35, 0x93, 0x8e, 0xda, 0xf0, 0x12, 0x82, 0x45,
			0x1d, 0xb5, 0xc2, 0x7d, 0x6a, 0x27, 0xf9, 0xb9,
			0xc9, 0x9a, 0x09, 0x78, 0x4d, 0xe4, 0x72, 0xa6,
			0x06, 0xbf, 0x8b, 0x62, 0x66, 0xdd, 0x30, 0xfd,
			0xe2, 0x98, 0x25, 0xb3, 0x10, 0x91, 0x22, 0x88,
			0x36, 0xd0, 0x94, 0xce, 0x8f, 0x96, 0xdb, 0xbd,
			0xf1, 0xd2, 0x13, 0x5c, 0x83, 0x38, 0x46, 0x40,
			0x1e, 0x42, 0xb6, 0xa3, 0xc3, 0x48, 0x7e, 0x6e,
			0x6b, 0x3a, 0x28, 0x54, 0xfa, 0x85, 0xba, 0x3d,
			0xca, 0x5e, 0x9b, 0x9f, 0x0a, 0x15, 0x79, 0x2b,
			0x4e, 0xd4, 0xe5, 0xac, 0x73, 0xf3, 0xa7, 0x57,
			0x07, 0x70, 0xc0, 0xf7, 0x8c, 0x80, 0x63, 0x0d,
			0x67, 0x4a, 0xde, 0xed, 0x31, 0xc5, 0xfe, 0x18,
			0xe3, 0xa5, 0x99, 0x77, 0x26, 0xb8, 0xb4, 0x7c,
			0x11, 0x44, 0x92, 0xd9, 0x23, 0x20, 0x89, 0x2e,
			0x37, 0x3f, 0xd1, 0x5b, 0x95, 0xbc, 0xcf, 0xcd,
			0x90, 0x87, 0x97, 0xb2, 0xdc, 0xfc, 0xbe, 0x61,
			0xf2, 0x56, 0xd3, 0xab, 0x14, 0x2a, 0x5d, 0x9e,
			0x84, 0x3c, 0x39, 0x53, 0x47, 0x6d, 0x41, 0xa2,
			0x1f, 0x2d, 0x43, 0xd8, 0xb7, 0x7b, 0xa4, 0x76,
			0xc4, 0x17, 0x49, 0xec, 0x7f, 0x0c, 0x6f, 0xf6,
			0x6c, 0xa1, 0x3b, 0x52, 0x29, 0x9d, 0x55, 0xaa,
			0xfb, 0x60, 0x86, 0xb1, 0xbb, 0xcc, 0x3e, 0x5a,
			0xcb, 0x59, 0x5f, 0xb0, 0x9c, 0xa9, 0xa0, 0x51,
			0x0b, 0xf5, 0x16, 0xeb, 0x7a, 0x75, 0x2c, 0xd7,
			0x4f, 0xae, 0xd5, 0xe9, 0xe6, 0xe7, 0xad, 0xe8,
			0x74, 0xd6, 0xf4, 0xea, 0xa8, 0x50, 0x58, 0xaf
		};

		static constexpr std::array<unsigned char, 256> ExponentialTable
		{
			0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
			0x1d, 0x3a, 0x74, 0xe8, 0xcd, 0x87, 0x13, 0x26,
			0x4c, 0x98, 0x2d, 0x5a, 0xb4, 0x75, 0xea, 0xc9,
			0x8f, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0,
			0x9d, 0x27, 0x4e, 0x9c, 0x25, 0x4a, 0x94, 0x35,
			0x6a, 0xd4, 0xb5, 0x77, 0xee, 0xc1, 0x9f, 0x23,
			0x46, 0x8c, 0x05, 0x0a, 0x14, 0x28, 0x50, 0xa0,
			0x5d, 0xba, 0x69, 0xd2, 0xb9, 0x6f, 0xde, 0xa1,
			0x5f, 0xbe, 0x61, 0xc2, 0x99, 0x2f, 0x5e, 0xbc,
			0x65, 0xca, 0x89, 0x0f, 0x1e, 0x3c, 0x78, 0xf0,
			0xfd, 0xe7, 0xd3, 0xbb, 0x6b, 0xd6, 0xb1, 0x7f,
			0xfe, 0xe1, 0xdf, 0xa3, 0x5b, 0xb6, 0x71, 0xe2,
			0xd9, 0xaf, 0x43, 0x86, 0x11, 0x22, 0x44, 0x88,
			0x0d, 0x1a, 0x34, 0x68, 0xd0, 0xbd, 0x67, 0xce,
			0x81, 0x1f, 0x3e, 0x7c, 0xf8, 0xed, 0xc7, 0x93,
			0x3b, 0x76, 0xec, 0xc5, 0x97, 0x33, 0x66, 0xcc,
			0x85, 0x17, 0x2e, 0x5c, 0xb8, 0x6d, 0xda, 0xa9,
			0x4f, 0x9e, 0x21, 0x42, 0x84, 0x15, 0x2a, 0x54,
			0xa8, 0x4d, 0x9a, 0x29, 0x52, 0xa4, 0x55, 0xaa,
			0x49, 0x92, 0x39, 0x72, 0xe4, 0xd5, 0xb7, 0x73,
			0xe6, 0xd1, 0xbf, 0x63, 0xc6, 0x91, 0x3f, 0x7e,
			0xfc, 0xe5, 0xd7, 0xb3, 0x7b, 0xf6, 0xf1, 0xff,
			0xe3, 0xdb, 0xab, 0x4b, 0x96, 0x31, 0x62, 0xc4,
			0x95, 0x37, 0x6e, 0xdc, 0xa5, 0x57, 0xae, 0x41,
			0x82, 0x19, 0x32, 0x64, 0xc8, 0x8d, 0x07, 0x0e,
			0x1c, 0x38, 0x70, 0xe0, 0xdd, 0xa7, 0x53, 0xa6,
			0x51, 0xa2, 0x59, 0xb2, 0x79, 0xf2, 0xf9, 0xef,
			0xc3, 0x9b, 0x2b, 0x56, 0xac, 0x45, 0x8a, 0x09,
			0x12, 0x24, 0x48, 0x90, 0x3d, 0x7a, 0xf4, 0xf5,
			0xf7, 0xf3, 0xfb, 0xeb, 0xcb, 0x8b, 0x0b, 0x16,
			0x2c, 0x58, 0xb0, 0x7d, 0xfa, 0xe9, 0xcf, 0x83,
			0x1b, 0x36, 0x6c, 0xd8, 0xad, 0x47, 0x8e, 0x00
		};


		GaloisFiniteField256() = default;

	public:
		ByteType addition_or_subtraction(ByteType left, ByteType right)
		{
			return left ^ right;
		}

		ByteType multiplication(ByteType left, ByteType right)
		{
			if( left == static_cast<ByteType>(0x00) || right == static_cast<ByteType>(0x00) )
				return static_cast<ByteType>(0x00);

			auto integer_a = static_cast<std::uint32_t>(left);
			auto integer_b = static_cast<std::uint32_t>(right);

			integer_a = static_cast<std::uint32_t>( LogarithmicTable[integer_a] );
			integer_b = static_cast<std::uint32_t>( LogarithmicTable[integer_b] );

			auto value = (integer_a + integer_b) % 255;

			return static_cast<ByteType>( ExponentialTable[value] );
		}

		ByteType division(ByteType left, ByteType right)
		{
			if( left == static_cast<ByteType>(0x00) )
				return static_cast<ByteType>(0x00);

			if( right == static_cast<ByteType>(0x00) )
				my_cpp2020_assert( false, "GaloisFiniteField256: divide by zero", std::source_location::current() );

			auto integer_a = static_cast<std::uint32_t>(left);
			auto integer_b = static_cast<std::uint32_t>(right);

			integer_a = static_cast<std::uint32_t>( LogarithmicTable[integer_a] );
			integer_b = static_cast<std::uint32_t>( LogarithmicTable[integer_b] );

			auto value = static_cast<std::int32_t>(integer_a - integer_b) % 255;
			if(value < 0)
				value += 255;

			return static_cast<ByteType>( ExponentialTable[value] );
		}

		// Returns the value of the polynomial for the given index_value.
		static ByteType evaluation_polynomials(GaloisFiniteField256& this_instance, std::vector<ByteType> polynomials, ByteType index_value)
		{
			ByteType result { 0 };

			// special case the origin
			if(index_value == static_cast<ByteType>(0x00))
			{
				return polynomials[0];
			}

			// compute the polynomial value using Horner's method.
			for(std::int32_t index = polynomials.size() - 1; index >= 0; index--)
			{
				// do multiplication then addition
				result = this_instance.addition_or_subtraction( this_instance.multiplication(result, index_value), polynomials[index] );
			}

			return result;
		}

		// Using the computed Lagrangian function(0), N sample points are extracted and the interpolated values of the given byte_points are returned.
		static ByteType polynomial_interpolation(GaloisFiniteField256& this_instance, std::vector<std::vector<ByteType>> byte_points)
		{
			const ByteType input_value { 0 };
			ByteType output_value { 0 };

			for(std::size_t round = 0; round < byte_points.size(); round++)
			{
				const ByteType axis_x_from_a = byte_points[round][0];
				const ByteType axis_y_from_a = byte_points[round][1];

				ByteType lagrangian_basis_value { 1 };

				for(std::size_t round2 = 0; round2 < byte_points.size(); round2++)
				{
					const ByteType axis_x_from_b = byte_points[round2][0];

					if(round != round2)
					{
						// do subtraction then division
						auto that_number = this_instance.addition_or_subtraction(input_value, axis_x_from_b);
						auto denominator_of_that_number = this_instance.addition_or_subtraction(axis_x_from_a, axis_x_from_b);
						auto quotient = this_instance.division(that_number, denominator_of_that_number);

						// do multiplication
						lagrangian_basis_value = this_instance.multiplication(lagrangian_basis_value, quotient);
					}
				}

				// do multiplication then addition
				output_value = this_instance.addition_or_subtraction(output_value, this_instance.multiplication(lagrangian_basis_value, axis_y_from_a) );
			}

			return output_value;
		}

		static GaloisFiniteField256& get_instance()
		{
			static GaloisFiniteField256 instance = GaloisFiniteField256();
			return instance;
		}

		~GaloisFiniteField256() = default;
	};
}

#endif //ALGORITHM_OALDRESPUZZLECRYPTIC_COMMONSECURITY_HPP
