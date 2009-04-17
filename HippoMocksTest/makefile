WARNFLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors
CXXOPTS0X = -std=c++0x -I../HippoMocks0x/ $(WARNFLAGS)
CXXOPTS = -std=c++98 -I../HippoMocks/ $(WARNFLAGS) -ansi
CXX = g++ $(CXXOPTS)
CXX0X = g++ $(CXXOPTS0X)
OBJECTS = test0x.exe is_virtual_0x.o test_0x.o test_args_0x.o test_class_args_0x.o test_class_mock_0x.o test_constref_params_0x.o test_cv_funcs_0x.o test_except_0x.o test_functors_0x.o test_optional_0x.o test_ref_args_0x.o test_retval_0x.o test_transaction_0x.o yaffut_0x.o test_exception_quality_0x.o test_nevercall_0x.o test_regression_arg_count_0x.o test.exe is_virtual.o test.o test_args.o test_class_args.o test_class_mock.o test_constref_params.o test_cv_funcs.o test_except.o test_functors.o test_optional.o test_ref_args.o test_retval.o test_transaction.o yaffut.o test_exception_quality.o test_nevercall.o test_regression_arg_count.o HippoMocksTest.ncb HippoMocksTest.suo

all: test.exe test0x.exe

clean:
	$(RM) $(OBJECTS)

%_0x.o: %.cpp 
	$(CXX0X) -c -o $@ $^

test0x.exe: is_virtual_0x.o test_0x.o test_args_0x.o test_class_args_0x.o test_class_mock_0x.o test_constref_params_0x.o test_cv_funcs_0x.o test_except_0x.o test_functors_0x.o test_optional_0x.o test_ref_args_0x.o test_retval_0x.o test_transaction_0x.o yaffut_0x.o test_exception_quality_0x.o test_nevercall_0x.o test_regression_arg_count_0x.o
	$(CXX) -o $@ $^

test.exe: is_virtual.o test.o test_args.o test_class_args.o test_class_mock.o test_constref_params.o test_cv_funcs.o test_except.o test_functors.o test_optional.o test_ref_args.o test_retval.o test_transaction.o yaffut.o test_exception_quality.o test_nevercall.o test_regression_arg_count.o
	$(CXX) -o $@ $^

