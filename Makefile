IMAGE_NAME := aoa-esp32			# Define the Docker image name
LOCAL_PROJECT_DIR := /Users/surajmandal/Desktop/dev/work/esp32_frimware		# Define your local project directory and build directory
BUILD_DIR := $(LOCAL_PROJECT_DIR)/build
BOARD := esp32:esp32:esp32 			# Define the board fully qualified board name
DOCKER_WORK_DIR := /workspace		# Define the Docker work directory

.PHONY: docker-build
docker-build:
	docker build -t $(IMAGE_NAME) .

.PHONY: compile
compile: docker-build
	docker run --rm -v "$(LOCAL_PROJECT_DIR):$(DOCKER_WORK_DIR)" $(IMAGE_NAME) arduino-cli compile --fqbn $(BOARD) $(DOCKER_WORK_DIR) --build-path $(DOCKER_WORK_DIR)/build

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*

all: compile
