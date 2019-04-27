/*
 *
 * Copyright 2018 Asylo authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <string>

#include "absl/strings/escaping.h"
#include "absl/strings/str_cat.h"
#include "asylo/crypto/aes_gcm_siv.h"
#include "asylo/trusted_application.h"
#include "asylo/util/cleansing_types.h"
#include "asylo/util/status_macros.h"
#include "asylo/util/statusor.h"
#include "xgboost_args.pb.h"

#include <fstream>

#ifndef arraysize
#define arraysize(arr) (sizeof(arr) / sizeof(arr[0]))
#endif

namespace asylo {

class XGBoostEnclave : public TrustedApplication {
 public:
  XGBoostEnclave() = default;

  Status Run(const EnclaveInput &input, EnclaveOutput *output) {
    return Status::OkStatus();
  }

  // Retrieves user message from |input|.
  const std::string GetEnclaveUserMessage(const EnclaveInput &input) {
    return input.GetExtension(guide::asylo::quickstart_input).value();
  }

  // Populates |enclave_output|->value() with |output_message|. Intended to be
  // used by the reader for completing the exercise.
  void SetEnclaveOutputMessage(EnclaveOutput *enclave_output,
                               const std::string &output_message) {
    guide::asylo::Demo *output =
        enclave_output->MutableExtension(guide::asylo::quickstart_output);
    output->set_value(output_message);
  }
};

TrustedApplication *BuildTrustedApplication() { return new XGBoostEnclave; }

}  // namespace asylo
