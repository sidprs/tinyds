
import metalcompute as mc
from array import array
print(dir(mc))

class MetalCompute:
    def __init__(self):
        kernel = """
        #include <metal_stdlib>
        using namespace metal;
        kernel void helloABC(const device float *A [[buffer(0)]],
                               const device float *B [[buffer(1)]],
                               device float *C [[buffer(2)]],
                               uint id [[thread_position_in_grid]]) {
            C[id] = A[id] * B[id]; 
        }
        """
        self.dev = mc.Device()
        self.count = 10
        self.helloABC = self.dev.kernel(kernel).function("helloABC")

if __name__ == "__main__":
    print("Hello, World!")
    
    metal = MetalCompute()
    
    # Create input arrays
    A = array('f', range(10))  # 0..9
    B = array('f', range(10, 20))  # 10...19
    C = metal.dev.buffer(metal.count * 4)  # 4 because a float32 needs 4 bytes 
    C_view = memoryview(C).cast('f')
    
    # Run the kernel count times
    metal.helloABC(metal.count, A, B, C)
    
    # Print the second result which should be 1.0 * 11.0 = 11.0
    print(C_view[1])
