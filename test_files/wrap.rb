#!/usr/bin/env ruby

require "parse_fasta"

wrap_len = ARGV[0].to_i

FastaFile.open(ARGV[1]).each_record do |head, seq|
  printf ">%s\n", head.gsub(/[_.,\/\\| =-]+/, "_")

  seq.each_char.each_slice(wrap_len).each { |sl| puts sl.join }
end
