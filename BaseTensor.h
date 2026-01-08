#ifndef BASETENSOR_H_
#define BASETENSOR_H_


#include <iostream>
#include <vector>
#include <random>

// Base class for all tensors
class BaseTensor {
public:

	/**
	 * Virtual method for load data to a tensor;
	 * Given the dimensions are different for each type
	 * of tensor, the loadData() function to initialize
	 * the values of a tensor should overriden by
	 * derived tensor classes;
	 */
    virtual void loadData() = 0;

    /**
     * virtual for valueGen() is optional;
     * valueGen() can use random library to generate values
     * to initialize the tensor values;
     */
    
	 double valueGen();

};

#endif /* BASETENSOR_H_ */
