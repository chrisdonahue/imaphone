#ifndef LOGGER_H
#define LOGGER_H

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <string>
#include <streambuf>
#include <sstream>
#include <stdio.h>
#include <iosfwd>
#include <iostream>
#include <vector>

namespace aux{
	struct log_params {
		bool to_file;
		bool to_cout;
		bool to_cerr;
	};

	// log stream
	class log : public std::streambuf {
		public:
			explicit log(log_params* params, std::string output_file_path, std::size_t buff_sz = 2048);
			~log();

			void set_forward(std::ostream* f);

		protected:
			bool forward_and_flush();

		private:
			log::int_type overflow(int_type ch);
			int sync();

			// copy ctor and assignment not implemented;
			// copying not allowed
			log(const log &);
			log &operator= (const log &);

			log_params* params;
			bool do_forward;
			std::ostream* forward;
			std::ofstream log_file_stream;
			std::stringstream sink_;
			std::vector<char> buffer_;
	};

	// params for log stream
	struct logger_params {
		aux::log_params* log_params;
		aux::log_params* verbose_params;
		aux::log_params* debug_params;
		aux::log_params* error_params;
		unsigned log_precision;
		bool verbose_to_log;
	};

	class logger {
		public:    
			logger(logger_params* params, std::string seed_string, std::string output_dir_path);
			~logger();

	#ifndef _WIN32
			std::string get_system_info();
	#endif

			std::string get_seed_string();

			std::ostream log;
			std::ostream verbose;
			std::ostream debug;
			std::ostream error;

		private:
			logger_params* params;
			std::string seed_string;

			aux::log log_buff;
			aux::log verbose_buff;
			aux::log debug_buff;
			aux::log error_buff;
	};
}

#endif
