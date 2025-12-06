BUILD_DIR = make
BUILD_TYPE = Debug

compile:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) .. && make -j$$(nproc)

run:
	@./$(BUILD_DIR)/src/bottrading

clean:
	rm -rf $(BUILD_DIR)

test:
	@cd $(BUILD_DIR) && make -j unit_tests
	@cd $(BUILD_DIR) && ctest --output-on-failure
