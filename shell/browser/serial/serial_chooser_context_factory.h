// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SHELL_BROWSER_SERIAL_SERIAL_CHOOSER_CONTEXT_FACTORY_H_
#define SHELL_BROWSER_SERIAL_SERIAL_CHOOSER_CONTEXT_FACTORY_H_

#include "base/memory/singleton.h"
#include "components/keyed_service/content/browser_context_keyed_service_factory.h"
#include "shell/browser/serial/serial_chooser_context.h"

namespace electron {

class SerialChooserContext;

class SerialChooserContextFactory : public BrowserContextKeyedServiceFactory {
 public:
  static SerialChooserContext* GetForBrowserContext(
      content::BrowserContext* context);
  static SerialChooserContextFactory* GetInstance();

 private:
  friend struct base::DefaultSingletonTraits<SerialChooserContextFactory>;

  SerialChooserContextFactory();
  ~SerialChooserContextFactory() override;

  // BrowserContextKeyedServiceFactory methods:
  KeyedService* BuildServiceInstanceFor(
      content::BrowserContext* context) const override;
  content::BrowserContext* GetBrowserContextToUse(
      content::BrowserContext* context) const override;

  DISALLOW_COPY_AND_ASSIGN(SerialChooserContextFactory);
};

}  // namespace electron

#endif  // SHELL_BROWSER_SERIAL_SERIAL_CHOOSER_CONTEXT_FACTORY_H_
