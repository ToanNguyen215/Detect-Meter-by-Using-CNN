#include "SD_MMC.h"

void setup() {
  Serial.begin(115200);

  if (!SD_MMC.begin()) {
    Serial.println("Failed to mount card");
    return;
  }

  File file2 = SD_MMC.open("/data2.txt", FILE_READ);

  if (!file2) {
    Serial.println("Opening file to read failed");
    return;
  }

  Serial.println("File Content:");

  const int maxSize = 5; // Maximum size of the array
  int arr[maxSize];      // Create an array to store the values
  int index = 0;         // Index to keep track of array position

  while (file2.available()) {
    int value = file2.parseInt(); // Read the next integer value from the file

    if (file2.peek() == ',') {
      file2.read(); // Read and discard the comma
    }

    arr[index] = value; // Store the value in the array
    index++;

    Serial.print(value);
    Serial.print(" ");
  }

  file2.close();

  Serial.println("\nArray Content:");
  for (int i = 0; i < index; i++) {
    Serial.print(arr[i]);
    Serial.print(" ");
  }
}

void loop() {
  }
