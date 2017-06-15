/**
 * Copyright 2017 Florentin Thullier.
 * <p/>
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * <p/>
 * http://www.apache.org/licenses/LICENSE-2.0
 * <p/>
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define FREQUENCY 60

long lastPrint = 0;
long lastFreq = 0;
int counter = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if ((millis() - lastFreq) > 1000) {
    lastFreq = millis();
    Serial.print(counter);
    Serial.println(" Hz");
    counter = 0;
  }

  if ((millis() - lastPrint) >= (1000 / FREQUENCY)) {
    lastPrint = millis();
    counter++;
  }
  
}
