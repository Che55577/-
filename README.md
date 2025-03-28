# Enigma 加密模擬器

這是一個簡單的 Enigma 機模擬程式，實現了基本的加密功能。Enigma 機器是二戰期間德國使用的加密設備，本程式模擬了其加密過程，透過旋轉的轉子與反射器來加密輸入的文字。

## 程式功能

- 使用 3 個轉子進行加密。
- 內建一個反射器來完成加密過程中的反向映射。
- 每次加密後，第三個轉子會自動旋轉。
- 支援加密英文字母並忽略空格。

## 程式運作

1. **輸入文字**：使用者輸入的文字會經過 Enigma 機加密。
2. **加密過程**：每個字母經過轉子的映射，再經過反射器進行反向映射，最後再經過轉子進行反向處理。
3. **轉子旋轉**：每次加密後，第三個轉子會旋轉，這會改變下一次加密的結果。

## 主要結構

- **Rotor (轉子)**: 包含轉子的映射和旋轉位置。
- **process_char 函式**: 用於處理字母通過轉子或反射器的加密過程。
- **enigma_encrypt 函式**: 用於加密單一字母，並且會處理轉子的旋轉。
- **REFLECTOR**: 反射器的映射，固定不變。
  
## 使用方式

1. 複製此程式碼至本地環境。
2. 使用 C++ 編譯器編譯並執行程式。
3. 輸入大寫字母文字（可包含空格）進行加密。

### 範例

```bash
請輸入想加密的文字：HELLO WORLD
加密結果: GDDXA XVDKZ
