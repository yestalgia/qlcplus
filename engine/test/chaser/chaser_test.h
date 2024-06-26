/*
  Q Light Controller - Unit test
  chaser_test.h

  Copyright (c) Heikki Junnila

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef CHASER_TEST_H
#define CHASER_TEST_H

#include <QObject>

class Doc;
class Chaser_Test : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void initial();
    void directionRunOrder();
    void steps();
    void stepAt();
    void functionRemoval();
    void copyFrom();
    void createCopy();
    void speedModes();

    void loadSuccessLegacy();
    void loadSuccess();
    void loadWrongType();
    void loadWrongRoot();
    void postLoad();
    void save();

    void tap();
    void preRun();
    void writeHTP();
    void writeLTP();
    void postRun();
    void adjustIntensity();

    void quickChaser();

private:
    Doc* m_doc;
};

#endif
