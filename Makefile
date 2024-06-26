build:
	docker build -t esp32_firmware .

run:
	docker stop esp32_firmware || true
	docker rm esp32_firmware || true
	docker run --name esp32_firmware -v $(shell pwd)/builds:/esp32_firmware/builds esp32_firmware

clean:
	docker rm esp32_firmware
	rm -rf builds/*

flash:
	arduino-cli upload -p dev/cu.usbmodem744DBD9FDC782 --fqbn esp32:esp32:nano_nora ./builds

all: build run

git-update:
	git add .
	git commit -m "Update"
	git push

git-build:
	git add builds/
	git commit -m "Add/Remove builds"
	git push

.PHONY: build run clean flash all
.PHONY: git-update git-build
