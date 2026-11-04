# Original winter-town icon artwork (snowy mountains, a cabin, a snowball), on the 108-unit
# adaptive-icon grid. The foreground stays inside the 66-unit safe zone (21..87).
BG = """
<defs>
  <linearGradient id="sky" x1="0" y1="0" x2="0" y2="1">
    <stop offset="0" stop-color="#141E44"/>
    <stop offset="0.45" stop-color="#2C4888"/>
    <stop offset="0.8" stop-color="#6F98D2"/>
    <stop offset="1" stop-color="#9DBEE6"/>
  </linearGradient>
  <linearGradient id="far" x1="0" y1="0" x2="0" y2="1">
    <stop offset="0" stop-color="#6B8BC4"/><stop offset="1" stop-color="#4E6DA8"/>
  </linearGradient>
  <linearGradient id="near" x1="0" y1="0" x2="0" y2="1">
    <stop offset="0" stop-color="#46659F"/><stop offset="1" stop-color="#33507F"/>
  </linearGradient>
</defs>
<rect x="0" y="0" width="108" height="108" fill="url(#sky)"/>
<g fill="#F4F6FF">
  <circle cx="22" cy="20" r="0.9"/><circle cx="36" cy="12" r="0.7"/><circle cx="58" cy="17" r="0.8"/>
  <circle cx="15" cy="34" r="0.6"/><circle cx="90" cy="34" r="0.7"/><circle cx="66" cy="8" r="0.6"/>
</g>
<circle cx="81" cy="21" r="7" fill="#FFF4D6"/>
<circle cx="84.5" cy="18.5" r="6.2" fill="#24387A" fill-opacity="0.0"/>
<path d="M-4 76 L14 48 L24 58 L40 32 L56 56 L68 44 L84 60 L96 46 L112 66 L112 90 L-4 90 Z" fill="url(#far)"/>
<path d="M14 48 L19 55.5 L16 54 L12.5 57 L10.6 53.3 Z M40 32 L47.6 43.6 L43.5 41.5 L40 45 L36.5 41 L32.6 43.3 Z
         M68 44 L73.5 50.6 L70 49.5 L67 52 L64.6 48.4 Z M96 46 L101.2 53 L98 52 L95.5 54.4 L92.6 51 Z" fill="#EEF4FF"/>
<path d="M-4 84 L10 66 L22 74 L32 62 L46 76 L60 64 L76 78 L90 66 L112 82 L112 96 L-4 96 Z" fill="url(#near)"/>
<path d="M32 62 L36.6 67.3 L33.6 66.4 L31 68.8 L28.5 66.4 Z M60 64 L64.6 68 L61.6 67.6 L59 69.6 L56.4 67.4 Z
         M90 66 L95 70 L92 69.6 L89.5 71.4 L86.8 69.3 Z" fill="#EEF4FF"/>
<path d="M-4 86 Q30 79 56 84 T112 82 L112 112 L-4 112 Z" fill="#CFDDF1"/>
<path d="M-4 92 Q36 85 70 91 T112 90 L112 112 L-4 112 Z" fill="#EEF4FC"/>
"""

FG = """
<!-- smoke -->
<g fill="#E9EEF8">
  <circle cx="56.5" cy="44" r="2.4" fill-opacity="0.75"/><circle cx="59" cy="39.5" r="3" fill-opacity="0.6"/>
  <circle cx="62.5" cy="34.5" r="3.6" fill-opacity="0.45"/>
</g>
<!-- chimney -->
<rect x="53.5" y="47" width="6" height="11" fill="#6B3322"/>
<rect x="52.6" y="45.6" width="7.8" height="2.6" rx="1.2" fill="#F7FAFF"/>
<!-- cabin body -->
<rect x="30" y="60" width="32" height="22" fill="#A8502F"/>
<g stroke="#83391F" stroke-width="1.1">
  <line x1="30" y1="65" x2="62" y2="65"/><line x1="30" y1="70" x2="62" y2="70"/>
  <line x1="30" y1="75" x2="62" y2="75"/><line x1="30" y1="80" x2="62" y2="80"/>
</g>
<!-- window -->
<rect x="35" y="64.5" width="10" height="9" rx="1" fill="#FFD36A"/>
<rect x="35" y="64.5" width="10" height="9" rx="1" fill="none" stroke="#5E2716" stroke-width="1.4"/>
<line x1="40" y1="64.5" x2="40" y2="73.5" stroke="#5E2716" stroke-width="1.1"/>
<line x1="35" y1="69" x2="45" y2="69" stroke="#5E2716" stroke-width="1.1"/>
<!-- door -->
<rect x="49.5" y="67" width="8" height="15" rx="1" fill="#5E2716"/>
<circle cx="55.5" cy="75" r="0.8" fill="#FFD36A"/>
<!-- roof with snow -->
<path d="M26 62 L46 44 L66 62 Z" fill="#5A2618"/>
<path d="M24.5 62.5 Q25 59.5 28 58.5 L46 42 L64 58.5 Q67 59.5 67.5 62.5 Q62 64.5 57 62.6 Q52 65 47 62.8 Q41 65.2 36 62.8 Q30.5 65 24.5 62.5 Z" fill="#F8FBFF"/>
<!-- snow drift the cabin and snowball sit in -->
<path d="M-12 94 Q20 80 38 82.6 Q52 84 64 84.8 Q84 85.6 120 93 L120 120 L-12 120 Z" fill="#F4F8FE"/>
<path d="M-12 94 Q20 80 38 82.6 Q52 84 64 84.8 Q84 85.6 120 93" fill="none" stroke="#D6E3F4" stroke-width="0.8"/>
<!-- snowball -->
<defs><clipPath id="ball"><circle cx="71" cy="78" r="11"/></clipPath></defs>
<circle cx="71" cy="78" r="11" fill="#BFD0EA"/>
<circle cx="68.6" cy="75.4" r="10.2" fill="#F9FBFF" clip-path="url(#ball)"/>
<circle cx="66" cy="72.6" r="2.4" fill="#FFFFFF"/>
<circle cx="75" cy="80" r="1.2" fill="#D5E1F2"/><circle cx="69" cy="82.2" r="0.9" fill="#D5E1F2"/><circle cx="73.4" cy="74.2" r="0.8" fill="#DDE7F5"/>
<!-- falling snow -->
<g fill="#FFFFFF">
  <circle cx="28" cy="40" r="1.3"/><circle cx="35" cy="30" r="1"/><circle cx="76" cy="52" r="1.2"/>
  <circle cx="82" cy="40" r="0.9"/><circle cx="24" cy="52" r="0.9"/><circle cx="68" cy="30" r="0.8"/>
</g>
"""

MONO = """
<g fill="#FFFFFF">
  <rect x="53.5" y="46" width="6" height="12"/>
  <path d="M24.5 62.5 L46 42 L67.5 62.5 L62 62.5 L62 82 L30 82 L30 62.5 Z"/>
  <circle cx="71" cy="78" r="11"/>
</g>
"""

def svg(body, view="0 0 108 108"):
    return f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="{view}" width="1080" height="1080">{body}</svg>'

open("bg.svg","w").write(svg(BG))
open("fg.svg","w").write(svg(FG))
open("mono.svg","w").write(svg(MONO))
open("full.svg","w").write(svg(BG+FG))
# Legacy icons: the central part of the composition (the launcher shows the whole tile).
open("legacy.svg","w").write(svg(BG+FG, view="15 15 78 78"))
